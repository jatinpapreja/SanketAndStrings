#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int k;
    cin>>k;
    char st[100005];
    cin>>st;
    int n=strlen(st);
    int a_count = 0,b_count=0;
    int max_length=0;
    //FOR a
    int left=0,right=0;
    for(right=0;right<n;right++)
    {
        int len;
        if(st[right]=='a')
        {
            len=right-left+1;
            max_length=max(max_length,len);
        }
        else
        {
            b_count++;
            if(b_count<=k)
            {
                len=right-left+1;
                max_length=max(max_length,len);

            }
            else
            {
                while(b_count>k)
                {
                    if(st[left]=='b')b_count--;
                    left++;
                }

            }
        }
    }

    //FOR b
     left=0,right=0;
    for(right=0;right<n;right++)
    {
        int len;
        if(st[right]=='b')
        {
            len=right-left+1;
            max_length=max(max_length,len);
        }
        else
        {
            a_count++;
            if(a_count<=k)
            {
                len=right-left+1;
                max_length=max(max_length,len);

            }
            else
            {
                while(a_count>k)
                {
                    if(st[left]=='a')a_count--;
                    left++;
                }

            }
        }
    }
    cout<<max_length<<endl;
    return 0;
}
