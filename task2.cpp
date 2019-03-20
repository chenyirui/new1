#include<iostream> 
#include<string> 
#include<iomanip> 
#include<algorithm> 
#include <queue>
using namespace std; 

class Bignum
{
private:
 vector<int>num;
 int len;
public:
Bignum getThis()
{
    return *this;
}
 Bignum(string p);
 Bignum(){len =0;};
 Bignum(short a)
 { vector<int>q;
     int i=0;
     if(a<0) 
     {
     q.push_back(0);
     }
     else q.push_back(1);
     while(a>=1)
     {
         q.insert(q.begin(),a%10);
     }
     this->num = q;
     this->len = q.size();
 }
  Bignum(long long a)
 { vector<int>q;
     int i=0;
     if(a<0) 
     {
     q.push_back(0);
     }
     else q.push_back(1);
     
     while(a>=1)
     {
         q.insert(q.begin(),a%10);
     }
     this->num = q;
     this->len = q.size();
 }
 Bignum(int a)
 { vector<int>q;
     int i=0;
          if(a<0) 
     {
     q.push_back(0);
     }
     else q.push_back(1);
     
     while(a>=1)
     {
         q.insert(q.begin(),a%10);
     }
     this->num = q;
     this->len = q.size();
 }
 Bignum(vector<int>h)
 {

     this->len = h.size();
     this->num = h;
 }
 ~Bignum()
  {
   cout << "over"<<endl;   
  }
 void showvalue()
 {
    for(vector<int>::iterator it=num.begin();it<num.end();it++)
    {
        cout<<*it;
    }
    cout<<endl;
 }
 friend ostream& operator<<(ostream &out,Bignum& a)
 {
      vector<int>u=a.getNum();
          for(vector<int>::iterator it=u.begin();it<u.end();it++)
     {
         out<<*it;
     }
     return out;
 }
 friend istream & operator>>( istream & is,Bignum & c)
{
    string s;
    is>>s;
    c.Setvalue(s);

    return is;
}
 void Change()
 {
     *this->num.begin()=(*this->num.begin()+1)%2;
 }
int getLen()
 {
    return this->len;
 }
vector<int> getNum()
 {
  return this->num;
 }
void Setvalue(string p)
 {
     if(p[0]=='-')
        {
         num.push_back(0);
         p.erase(p.begin(),p.begin()+1);
        }
     else num.push_back(1);
     len = p.size()+1;
    for(int i=0;i<p.size();i++)
    {
     num.push_back(p[i]-'0');
    }
 }
 Bignum operator +(Bignum& b)
 {
      vector<int>s;
     int temp = 0,now=0;
 int h=max(this->getLen(),b.getLen());
 vector<int>u=b.getNum();
 vector<int>v=this->getNum();

 if(u.size()<h) u.insert(u.begin()+1,h-u.size(),0);
 if(v.size()<h) v.insert(v.begin()+1,h-v.size(),0);

  if(*u.begin()==*v.begin())
  {
 for(int i=0;i<h-1;i++)
 {  now = u.back()+ v.back()+temp;
   u.pop_back();
   v.pop_back();
     if(now>=10) 
     {
         now -=10;
         temp=1;

     }
     else 
     {
         temp = 0;
     }
     s.insert(s.begin(),now);
     now = 0;
 
  }
 if(temp>0)  
 {s.insert(s.begin(),temp);
 }
 s.insert(s.begin(),*u.begin());
 Bignum p(s);
 return p;
  }
  else
  {
      *u.begin()=(*u.begin()+1)%2;
      Bignum p(u);
      return *this - p;

  }
 }
  bool operator >(Bignum& b)
   {    if(*this->getNum().begin()&&*b.getNum().begin())
       {
           if(this->len>b.getLen())
        return true;
       else if(this->len<b.getLen())
        return false;
        else
        { vector<int> u= b.getNum();
           vector<int>::iterator a=num.begin();
           vector<int>::iterator b=u.begin();
        while(a!=num.end())
        {
            if(*a>*b) return true;
            a++;
            b++;
        }
        return false;
        }
       }
       else if(!*this->getNum().begin()&&!*b.getNum().begin())
       {
        vector<int>u=b.getNum();
        vector<int>v=this->getNum();
        *u.begin() = 1;
        *v.begin() = 1;
        Bignum U (u);
        Bignum V(v);
        return V<U;
       }
       else return *this->getNum().begin()>*b.getNum().begin();
   }
    bool operator<(Bignum& b)
   {
        if(*this->getNum().begin()&&*b.getNum().begin())
       {
           if(this->len>b.getLen())
        return false;
       else if(this->len<b.getLen())
        return true;
        else
        { vector<int> u= b.getNum();
          vector<int>::iterator a=num.begin();
          vector<int>::iterator b=u.begin();
        while(a!=num.end())
        {
            if(*a<*b) return true;
                        a++;
            b++;
        }
        return false;
        }
       }
       else if(!*this->getNum().begin()&&!*b.getNum().begin())
       {
        vector<int>u=b.getNum();
        vector<int>v=this->getNum();
        *u.begin() = 1;
        *v.begin() = 1;
        Bignum U (u);
        Bignum V(v);
        return V>U;
       }
       else return *this->getNum().begin()<*b.getNum().begin();
      
   }
  
Bignum operator-(Bignum& b)
 {
    vector<int>s;
    int temp = 0,now=0;
    int h=max(this->getLen(),b.getLen());
    vector<int>v=b.getNum();
    vector<int>u=this->getNum();

   if(u.size()<h) u.insert(u.begin()+1,h-u.size(),0);
   if(v.size()<h) v.insert(v.begin()+1,h-v.size(),0);
  if(*u.begin()&&*v.begin())
  {if((*this) > b)
  {
    //   cout<<endl<<"here"<<endl;
  for(int i=0;i<h-1;i++)
  {  now = u.back()- v.back()-temp;
//   cout<<u.back()<<v.back()<<endl;
   u.pop_back();
   v.pop_back();
     if(now<0) 
     {
         now += 10;
         temp=1;

     }
     else 
     {
         temp = 0;
     }
     s.insert(s.begin(),now);
     now = 0;
 
  }
 s.insert(s.begin(),*u.begin());
 Bignum p(s);
 return p;
  }

  else 
  {
      Bignum p = b - *this;
       p.Change();
      return p;
      

  }
  }
  else
  {
      *u.begin()=(*u.begin()+1)%2;
      Bignum p(u);
      return *this + p;

  }
 }


 Bignum operator*(Bignum &b)   //两个大数之间的相乘运算 
{ 
	vector<int>now(500); 
	int i,j,up; 
	int temp,temp1;   
    vector<int>v=b.getNum();
    vector<int>u=this->getNum();
    int Fir = (*v.begin()+(*u.begin())+1)%2;
    vector<int>::iterator k = u.begin();
    vector<int>::iterator l = v.begin();
    u.erase(k);
    v.erase(l);
    reverse(u.begin(),u.end());
    reverse(v.begin(),v.end());
	for(i = 0 ; i < u.size() ; i++)
	{ 
		up = 0; 
		for(j = 0 ; j < v.size() ; j++)
		{ 
			temp = u[i] * v[j] + now[i + j] + up; 
			if(temp > 9)
			{ 
				temp1 = temp - temp / (10) * (10); 
				up = temp / (10); 
				now[i + j] = temp1; 
			} 
			else
			{ 
				up = 0; 
				now[i + j] = temp; 
			} 
		} 
		if(up != 0) 
			now[i + j] = up; 
	} 
        vector<int>::iterator it1 = now.end();

        for(;;it1--)
        {
            
            if(*it1==0) now.pop_back();
            else break;
        }
        reverse(now.begin(),now.end());
    now.insert(now.begin(),Fir);
	return Bignum(now); 
} 
 };
 Bignum :: Bignum(string p)
{
     if(p[0]=='-')
        {
         num.push_back(0);
         p.erase(p.begin(),p.begin()+1);
        }
     else num.push_back(1);
     len = p.size()+1;
    for(int i=0;i<p.size();i++)
    {
     num.push_back(p[i]-'0');
    }
}
int main()
{
  string a ="58";
  string b ="96235";
  Bignum s = Bignum(a);
  Bignum t = Bignum(b);
    if(t<s) cout<<"right";
  else cout << "wrong";
  
  Bignum p = s*t;
    Bignum q = s-t;
   Bignum j =t-s;
  cout<<j<<endl<<p<<endl<<q;
    return 0;

}