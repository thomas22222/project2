#include<iostream>
#include<string>
#include<fstream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int a[60000000];
char map[1000][1000];
int intmap[4][1000][1000]={0};
int boo[4][4]={0};

int sum=0;
int x;
int y;
int zz;
int ri ;
int rj ;
int ss[4]={0};
//string id3="105000017/finalll.path";
//ofstream outf(id3,ios::out);


int BSF(int h,int si,int sj)
{
    
    queue<int> change[2];
    //cout<<'z'<<z<<endl;
    change[1].push(si);
    change[1].push(sj);
    int b;
    b=zz;
    int j;
    int z;
    //cout<<z<<endl;
    for (int i=1;i<b;i++)
    {
        //cout<<i<<endl;
        while(!change[i%2].empty())
        {
            j=change[i%2].front();
            change[i%2].pop();
            z=change[i%2].front();
            change[i%2].pop();
            ss[h]++;
            //cout<<j<<endl;
            //cout<<z<<endl;
                    /////


            if(j+1<x)
            {
                if(map[j+1][z]=='0'&&intmap[h][j+1][z]==0)
                {
                    intmap[h][j+1][z]=i+1;
                    change[(i+1)%2].push(j+1);
                    change[(i+1)%2].push(z);ss[h]++;
                }
            }
            if(j-1>-1)
            {
                if(map[j-1][z]=='0'&&intmap[h][j-1][z]==0)
                {
                    intmap[h][j-1][z]=i+1;
                    change[(i+1)%2].push(j-1);
                    change[(i+1)%2].push(z);ss[h]++;
                }
            }
            if(z+1<y)
            {
                if(map[j][z+1]=='0'&&intmap[h][j][z+1]==0)
                {
                    intmap[h][j][z+1]=i+1;
                    change[(i+1)%2].push(j);
                    change[(i+1)%2].push(z+1);ss[h]++;
                }
            }
            if(z-1>-1)
                {
                if(map[j][z-1]=='0'&&intmap[h][j][z-1]==0)
                {
                    intmap[h][j][z-1]=i+1;
                    change[(i+1)%2].push(j);
                    change[(i+1)%2].push(z-1);ss[h]++;
                }
            }
        }
    }
}

int change(int s,int p)
{
    int si;
    int sj;
    int ai;
    int aj;
    if((s+p)%4==0)
    {
        si=ri+1;
        sj=rj;
    }
    if((s+p)%4==1)
    {
        si=ri;
        sj=rj-1;
    }
    if((s+p)%4==2)
    {
        si=ri-1;
        sj=rj;
    }
    if((s+p)%4==3)
    {
        si=ri;
        sj=rj+1;
    }
    if(s==0)
    {
        ai=ri+1;
        aj=rj;
    }
    if(s==1)
    {
        ai=ri;
        aj=rj-1;
    }
    if(s==2)
    {
        ai=ri-1;
        aj=rj;
    }
    if(s==3)
    {
        ai=ri;
        aj=rj+1;
    }
    stack<int>back;
    back.push(rj);
    back.push(ri);
    back.push(sj);
    back.push(si);
    cout<<si<<endl;
    cout<<sj<<endl;
    cout<<ri<<endl;
    cout<<rj<<endl;

    cout<<ai<<endl;
    cout<<aj<<endl;
    while(1)
    {
        int pp=1;
        if(si-1>-1)
        {
            if(intmap[s][si-1][sj]==intmap[s][si][sj]-1&&intmap[s][si-1][sj]!=0&&pp)
            {
                back.push(sj);
                back.push(si-1);
                si=si-1;
                pp=0;
            }
        }
        if(si+1<x)
        {
            if(intmap[s][si+1][sj]==intmap[s][si][sj]-1&&intmap[s][si+1][sj]!=0&&pp)
            {
                back.push(sj);
                back.push(si+1);
                si=si+1;
                pp=0;
            }
        }
        if(sj-1>-1)
        {
            if(intmap[s][si][sj-1]==intmap[s][si][sj]-1&&intmap[s][si][sj-1]!=0&&pp)
            {
                back.push(sj-1);
                back.push(si);
                sj--;
                pp=0;
            }
        }
        if(sj+1<y)
        {
            if(intmap[s][si][sj+1]==intmap[s][si][sj]-1&&intmap[s][si][sj+1]!=0&&pp)
            {
                back.push(sj+1);
                back.push(si);
                sj++;
                pp=0;
            }
        }
        if(pp==1)
        {
            break;
        }
        pp=1;
    }
        cout<<11111<<endl;
    while(!back.empty())
    {
        a[sum]=back.top();
        back.pop();
        a[sum+1]=back.top();
        back.pop();
        sum+=2;
    }
    return (s+p)%4;
    
}
void mark(int s)
{
cout<<"sssssssssss"<<' '<<"mark"<<s<<endl;
    int ai;
    int aj;
    int si;
    int sj;
    if(s==0)
    {
        ai=ri+1;
        aj=rj;
    }
    if(s==1)
    {
        ai=ri;
        aj=rj-1;
    }
    if(s==2)
    {
        ai=ri-1;
        aj=rj;
    }
    if(s==3)
    {
        ai=ri;
        aj=rj+1;
    }

      
    int aa=0,bb=0,cc=0,dd=0;
    int ii=0,jj=0;
    while(1)
    {
        for (;jj<y-bb;jj++)
        {
             if(map[ii][jj]=='0'&&intmap[s][ii][jj]<=zz/2&&intmap[s][ii][jj]!=0)
            {
                si=ii;
                sj=jj;
                ai=ii;
                aj=jj;
                map[si][sj]='2';
                int ll=sum+(intmap[s][ii][jj]*2)-1;
                sum=sum+(intmap[s][ii][jj]*2);
                a[ll--]=sj;
                a[ll--]=si;
                    while(1)
                    {
                        int pp=1;
                        int ppp=1;
                        if(si-1>-1)
                        {
                            if(intmap[s][si-1][sj]==intmap[s][si][sj]-1&&intmap[s][si-1][sj]!=0&&pp&&map[si-1][sj]=='0')
                            {
                                
                                si=si-1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(si+1<x)
                        {
                            if(intmap[s][si+1][sj]==intmap[s][si][sj]-1&&intmap[s][si+1][sj]!=0&&pp&&map[si+1][sj]=='0')
                            {
                                
                                si=si+1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(sj-1>-1)
                        {
                            if(intmap[s][si][sj-1]==intmap[s][si][sj]-1&&intmap[s][si][sj-1]!=0&&pp&&map[si][sj-1]=='0')
                            {
                                sj--;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(sj+1<y)
                        {
                            if(intmap[s][si][sj+1]==intmap[s][si][sj]-1&&intmap[s][si][sj+1]!=0&&pp&&map[si][sj+1]=='0')
                            {
                                sj++;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(si-1>-1)
                        {
                            if(intmap[s][si-1][sj]==intmap[s][si][sj]-1&&intmap[s][si-1][sj]!=0&&pp)
                            {
                                si=si-1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(si+1<x)
                        {
                            if(intmap[s][si+1][sj]==intmap[s][si][sj]-1&&intmap[s][si+1][sj]!=0&&pp)
                            {
                                si=si+1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(sj-1>-1)
                        {
                            if(intmap[s][si][sj-1]==intmap[s][si][sj]-1&&intmap[s][si][sj-1]!=0&&pp)
                            {
                                sj--;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(sj+1<y)
                        {
                            if(intmap[s][si][sj+1]==intmap[s][si][sj]-1&&intmap[s][si][sj+1]!=0&&pp)
                            {
                                sj++;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(ai-1>-1)
                        {
                            if(intmap[s][ai-1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai-1][aj]!=0&&ppp&&map[ai-1][aj]=='0')
                            {
                                
                                ai=ai-1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai+1<x)
                        {
                            if(intmap[s][ai+1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai+1][aj]!=0&&ppp&&map[ai+1][aj]=='0')
                            {
                                
                                ai=ai+1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                                
                            }
                        }
                        if(aj-1>-1)
                        {
                            if(intmap[s][ai][aj-1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj-1]!=0&&ppp&&map[ai][aj-1]=='0')
                            {
                                aj--;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(aj+1<y)
                        {
                            if(intmap[s][ai][aj+1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj+1]!=0&&ppp&&map[ai][aj+1]=='0')
                            {
                                aj++;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai-1>-1)
                        {
                            if(intmap[s][ai-1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai-1][aj]!=0&&ppp)
                            {
                                
                                ai=ai-1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai+1<x)
                        {
                            if(intmap[s][ai+1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai+1][aj]!=0&&ppp)
                            {
                                
                                ai=ai+1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                                
                            }
                        }
                        if(aj-1>-1)
                        {
                            if(intmap[s][ai][aj-1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj-1]!=0&&ppp)
                            {
                                aj--;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(aj+1<y)
                        {
                            if(intmap[s][ai][aj+1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj+1]!=0&&ppp)
                            {
                                aj++;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(pp==1)
                        {
                            break;
                        }
                        pp=1;ppp=1;
                    }
                    a[sum++]=ri;
                    a[sum++]=rj;
            }
        }aa++;jj--;ii++;if(dd+bb==y||aa+cc==x)break;
        for (;ii<x-cc;ii++)
        {
            if(map[ii][jj]=='0'&&intmap[s][ii][jj]<=zz/2&&intmap[s][ii][jj]!=0)
            {
                si=ii;
                sj=jj;
                ai=ii;
                aj=jj;
                map[si][sj]='2';
                int ll=sum+(intmap[s][ii][jj]*2)-1;
                sum=sum+(intmap[s][ii][jj]*2);
                a[ll--]=sj;
                a[ll--]=si;
                    while(1)
                    {
                        int pp=1;
                        int ppp=1;
                        if(si-1>-1)
                        {
                            if(intmap[s][si-1][sj]==intmap[s][si][sj]-1&&intmap[s][si-1][sj]!=0&&pp&&map[si-1][sj]=='0')
                            {
                                
                                si=si-1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(si+1<x)
                        {
                            if(intmap[s][si+1][sj]==intmap[s][si][sj]-1&&intmap[s][si+1][sj]!=0&&pp&&map[si+1][sj]=='0')
                            {
                                
                                si=si+1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(sj-1>-1)
                        {
                            if(intmap[s][si][sj-1]==intmap[s][si][sj]-1&&intmap[s][si][sj-1]!=0&&pp&&map[si][sj-1]=='0')
                            {
                                sj--;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(sj+1<y)
                        {
                            if(intmap[s][si][sj+1]==intmap[s][si][sj]-1&&intmap[s][si][sj+1]!=0&&pp&&map[si][sj+1]=='0')
                            {
                                sj++;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(si-1>-1)
                        {
                            if(intmap[s][si-1][sj]==intmap[s][si][sj]-1&&intmap[s][si-1][sj]!=0&&pp)
                            {
                                si=si-1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(si+1<x)
                        {
                            if(intmap[s][si+1][sj]==intmap[s][si][sj]-1&&intmap[s][si+1][sj]!=0&&pp)
                            {
                                si=si+1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(sj-1>-1)
                        {
                            if(intmap[s][si][sj-1]==intmap[s][si][sj]-1&&intmap[s][si][sj-1]!=0&&pp)
                            {
                                sj--;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(sj+1<y)
                        {
                            if(intmap[s][si][sj+1]==intmap[s][si][sj]-1&&intmap[s][si][sj+1]!=0&&pp)
                            {
                                sj++;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(ai-1>-1)
                        {
                            if(intmap[s][ai-1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai-1][aj]!=0&&ppp&&map[ai-1][aj]=='0')
                            {
                                
                                ai=ai-1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai+1<x)
                        {
                            if(intmap[s][ai+1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai+1][aj]!=0&&ppp&&map[ai+1][aj]=='0')
                            {
                                
                                ai=ai+1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                                
                            }
                        }
                        if(aj-1>-1)
                        {
                            if(intmap[s][ai][aj-1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj-1]!=0&&ppp&&map[ai][aj-1]=='0')
                            {
                                aj--;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(aj+1<y)
                        {
                            if(intmap[s][ai][aj+1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj+1]!=0&&ppp&&map[ai][aj+1]=='0')
                            {
                                aj++;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai-1>-1)
                        {
                            if(intmap[s][ai-1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai-1][aj]!=0&&ppp)
                            {
                                
                                ai=ai-1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai+1<x)
                        {
                            if(intmap[s][ai+1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai+1][aj]!=0&&ppp)
                            {
                                
                                ai=ai+1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                                
                            }
                        }
                        if(aj-1>-1)
                        {
                            if(intmap[s][ai][aj-1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj-1]!=0&&ppp)
                            {
                                aj--;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(aj+1<y)
                        {
                            if(intmap[s][ai][aj+1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj+1]!=0&&ppp)
                            {
                                aj++;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(pp==1)
                        {
                            break;
                        }
                        pp=1;ppp=1;
                    }
                    a[sum++]=ri;
                    a[sum++]=rj;
            }
        }bb++;ii--;jj--;if(dd+bb==y||aa+cc==x)break;
        for (;jj>=0+dd;jj--)
        {
             if(map[ii][jj]=='0'&&intmap[s][ii][jj]<=zz/2&&intmap[s][ii][jj]!=0)
            {
                si=ii;
                sj=jj;
                ai=ii;
                aj=jj;
                map[si][sj]='2';
                int ll=sum+(intmap[s][ii][jj]*2)-1;
                sum=sum+(intmap[s][ii][jj]*2);
                a[ll--]=sj;
                a[ll--]=si;
                    while(1)
                    {
                        int pp=1;
                        int ppp=1;
                        if(si-1>-1)
                        {
                            if(intmap[s][si-1][sj]==intmap[s][si][sj]-1&&intmap[s][si-1][sj]!=0&&pp&&map[si-1][sj]=='0')
                            {
                                
                                si=si-1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(si+1<x)
                        {
                            if(intmap[s][si+1][sj]==intmap[s][si][sj]-1&&intmap[s][si+1][sj]!=0&&pp&&map[si+1][sj]=='0')
                            {
                                
                                si=si+1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(sj-1>-1)
                        {
                            if(intmap[s][si][sj-1]==intmap[s][si][sj]-1&&intmap[s][si][sj-1]!=0&&pp&&map[si][sj-1]=='0')
                            {
                                sj--;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(sj+1<y)
                        {
                            if(intmap[s][si][sj+1]==intmap[s][si][sj]-1&&intmap[s][si][sj+1]!=0&&pp&&map[si][sj+1]=='0')
                            {
                                sj++;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(si-1>-1)
                        {
                            if(intmap[s][si-1][sj]==intmap[s][si][sj]-1&&intmap[s][si-1][sj]!=0&&pp)
                            {
                                si=si-1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(si+1<x)
                        {
                            if(intmap[s][si+1][sj]==intmap[s][si][sj]-1&&intmap[s][si+1][sj]!=0&&pp)
                            {
                                si=si+1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(sj-1>-1)
                        {
                            if(intmap[s][si][sj-1]==intmap[s][si][sj]-1&&intmap[s][si][sj-1]!=0&&pp)
                            {
                                sj--;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(sj+1<y)
                        {
                            if(intmap[s][si][sj+1]==intmap[s][si][sj]-1&&intmap[s][si][sj+1]!=0&&pp)
                            {
                                sj++;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(ai-1>-1)
                        {
                            if(intmap[s][ai-1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai-1][aj]!=0&&ppp&&map[ai-1][aj]=='0')
                            {
                                
                                ai=ai-1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai+1<x)
                        {
                            if(intmap[s][ai+1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai+1][aj]!=0&&ppp&&map[ai+1][aj]=='0')
                            {
                                
                                ai=ai+1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                                
                            }
                        }
                        if(aj-1>-1)
                        {
                            if(intmap[s][ai][aj-1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj-1]!=0&&ppp&&map[ai][aj-1]=='0')
                            {
                                aj--;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(aj+1<y)
                        {
                            if(intmap[s][ai][aj+1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj+1]!=0&&ppp&&map[ai][aj+1]=='0')
                            {
                                aj++;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai-1>-1)
                        {
                            if(intmap[s][ai-1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai-1][aj]!=0&&ppp)
                            {
                                
                                ai=ai-1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai+1<x)
                        {
                            if(intmap[s][ai+1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai+1][aj]!=0&&ppp)
                            {
                                
                                ai=ai+1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                                
                            }
                        }
                        if(aj-1>-1)
                        {
                            if(intmap[s][ai][aj-1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj-1]!=0&&ppp)
                            {
                                aj--;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(aj+1<y)
                        {
                            if(intmap[s][ai][aj+1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj+1]!=0&&ppp)
                            {
                                aj++;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(pp==1)
                        {
                            break;
                        }
                        pp=1;ppp=1;
                    }
                    a[sum++]=ri;
                    a[sum++]=rj;
            }
        }cc++;jj++;ii--;if(dd+bb==y||aa+cc==x)break;
        for (;ii>=0+aa;ii--)
        {
             if(map[ii][jj]=='0'&&intmap[s][ii][jj]<=zz/2&&intmap[s][ii][jj]!=0)
            {
                si=ii;
                sj=jj;
                ai=ii;
                aj=jj;
                map[si][sj]='2';
                int ll=sum+(intmap[s][ii][jj]*2)-1;
                sum=sum+(intmap[s][ii][jj]*2);
                a[ll--]=sj;
                a[ll--]=si;
                    while(1)
                    {
                        int pp=1;
                        int ppp=1;
                        if(si-1>-1)
                        {
                            if(intmap[s][si-1][sj]==intmap[s][si][sj]-1&&intmap[s][si-1][sj]!=0&&pp&&map[si-1][sj]=='0')
                            {
                                
                                si=si-1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(si+1<x)
                        {
                            if(intmap[s][si+1][sj]==intmap[s][si][sj]-1&&intmap[s][si+1][sj]!=0&&pp&&map[si+1][sj]=='0')
                            {
                                
                                si=si+1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(sj-1>-1)
                        {
                            if(intmap[s][si][sj-1]==intmap[s][si][sj]-1&&intmap[s][si][sj-1]!=0&&pp&&map[si][sj-1]=='0')
                            {
                                sj--;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(sj+1<y)
                        {
                            if(intmap[s][si][sj+1]==intmap[s][si][sj]-1&&intmap[s][si][sj+1]!=0&&pp&&map[si][sj+1]=='0')
                            {
                                sj++;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(si-1>-1)
                        {
                            if(intmap[s][si-1][sj]==intmap[s][si][sj]-1&&intmap[s][si-1][sj]!=0&&pp)
                            {
                                si=si-1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(si+1<x)
                        {
                            if(intmap[s][si+1][sj]==intmap[s][si][sj]-1&&intmap[s][si+1][sj]!=0&&pp)
                            {
                                si=si+1;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                                
                            }
                        }
                        if(sj-1>-1)
                        {
                            if(intmap[s][si][sj-1]==intmap[s][si][sj]-1&&intmap[s][si][sj-1]!=0&&pp)
                            {
                                sj--;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(sj+1<y)
                        {
                            if(intmap[s][si][sj+1]==intmap[s][si][sj]-1&&intmap[s][si][sj+1]!=0&&pp)
                            {
                                sj++;
                                a[ll--]=sj;
                                a[ll--]=si;
                                map[si][sj]='2';
                                pp=0;
                            }
                        }
                        if(ai-1>-1)
                        {
                            if(intmap[s][ai-1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai-1][aj]!=0&&ppp&&map[ai-1][aj]=='0')
                            {
                                
                                ai=ai-1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai+1<x)
                        {
                            if(intmap[s][ai+1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai+1][aj]!=0&&ppp&&map[ai+1][aj]=='0')
                            {
                                
                                ai=ai+1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                                
                            }
                        }
                        if(aj-1>-1)
                        {
                            if(intmap[s][ai][aj-1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj-1]!=0&&ppp&&map[ai][aj-1]=='0')
                            {
                                aj--;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(aj+1<y)
                        {
                            if(intmap[s][ai][aj+1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj+1]!=0&&ppp&&map[ai][aj+1]=='0')
                            {
                                aj++;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai-1>-1)
                        {
                            if(intmap[s][ai-1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai-1][aj]!=0&&ppp)
                            {
                                
                                ai=ai-1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(ai+1<x)
                        {
                            if(intmap[s][ai+1][aj]==intmap[s][ai][aj]-1&&intmap[s][ai+1][aj]!=0&&ppp)
                            {
                                
                                ai=ai+1;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                                
                            }
                        }
                        if(aj-1>-1)
                        {
                            if(intmap[s][ai][aj-1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj-1]!=0&&ppp)
                            {
                                aj--;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(aj+1<y)
                        {
                            if(intmap[s][ai][aj+1]==intmap[s][ai][aj]-1&&intmap[s][ai][aj+1]!=0&&ppp)
                            {
                                aj++;
                                a[sum++]=ai;
                                a[sum++]=aj;
                                map[ai][aj]='2';
                                ppp=0;
                            }
                        }
                        if(pp==1)
                        {
                            break;
                        }
                        pp=1;ppp=1;
                    }
                    a[sum++]=ri;
                    a[sum++]=rj;
            }
        }dd++;ii++;jj++;if(dd+bb==y||aa+cc==x)break;
    }
    


}

int main(int agrc,char *agrv[])
{
for(int nn=0;nn<agrc-1;nn++){
    //cout<<agrc<<endl;
    string id,id2;
    id=agrv[nn+1];
    id2=agrv[nn+1];
    cout<<id<<endl;
    id+="/floor.data";
    //string idn="../";     //桌面
    //id=idn+id;
    //string url;
    //url="test_case_v2\\test_case\\";
    //id=url+id;
    ifstream infile(id,ios::in);
    if(!infile){cout<<id<<' '<<"errrror"<<endl;
    return 1;}
    infile>>x;
    infile>>y;
    cout<<x<<' '<<y<<endl;
    infile>>zz;
    cout<<zz;
    int rsum=0;
    
    //int ri,rj;
    for(int i=0 ;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {   
            infile>>map[i][j];
            if (map[i][j]=='R')
            {
                ri=i;
                rj=j;
            }    
        }   
    }
    cout<<ri<<' '<<rj<<endl;

    if(ri+1<x)
    {
        if(map[ri+1][rj]=='0')
        {
            intmap[0][ri+1][rj]=1;
            BSF(0,ri+1,rj);
            boo[0][0]=1;
            rsum+=1;
        }
    }
    if(ri-1>-1)
    {
        if(map[ri-1][rj]=='0')
        {
            intmap[2][ri-1][rj]=1;
            BSF(2,ri-1,rj);
            boo[2][2]=1;
            rsum+=1;
        }
    }
    if(rj+1<y)
    {
        if(map[ri][rj+1]=='0')
        {
            intmap[3][ri][rj+1]=1;
            BSF(3,ri,rj+1);
            boo[3][3]=1;
            rsum+=1;
        }
    }
    if(rj-1>-1)
    {
        if(map[ri][rj-1]=='0')
        {
            intmap[1][ri][rj-1]=1;
            BSF(1,ri,rj-1);
            boo[1][1]=1;
            rsum+=1;
        }
    }
    ///////
    if(boo[0][0]==1)
    {
        if(intmap[0][ri][rj-1]!=0&&intmap[0][ri][rj-1]!=zz)
        {
            boo[0][1]=1;
        }
        if(intmap[0][ri-1][rj]!=0&&intmap[0][ri-1][rj]!=zz)
        {
            boo[0][2]=1;
        }
        if(intmap[0][ri][rj+1]!=0&&intmap[0][ri][rj+1]!=zz)
        {
            boo[0][3]=1;
        }
    }
    if(boo[1][1]==1)
    {
        if(intmap[1][ri+1][rj]!=0&&intmap[1][ri+1][rj]!=zz)
        {
            boo[1][0]=1;
        }
        if(intmap[1][ri-1][rj]!=0&&intmap[1][ri-1][rj]!=zz)
        {
            boo[1][2]=1;
        }
        if(intmap[1][ri][rj+1]!=0&&intmap[1][ri][rj+1]!=zz)
        {
            boo[1][3]=1;
        }
    }
    if(boo[2][2]==1)
    {
        if(intmap[2][ri+1][rj]!=0&&intmap[2][ri+1][rj]!=zz)
        {
            boo[2][0]=1;
        }
        if(intmap[2][ri][rj-1]!=0&&intmap[2][ri][rj-1]!=zz)
        {
            boo[2][1]=1;
        }
        if(intmap[2][ri][rj+1]!=0&&intmap[2][ri][rj+1]!=zz)
        {
            boo[2][3]=1;
        }
    }
    if(boo[3][3]==1)
    {
        if(intmap[3][ri+1][rj]!=0&&intmap[3][ri+1][rj]!=zz)
        {
            boo[3][0]=1;
        }
        if(intmap[3][ri][rj-1]!=0&&intmap[3][ri][rj-1]!=zz)
        {
            boo[3][1]=1;
        }
        if(intmap[3][ri-1][rj]!=0&&intmap[3][ri-1][rj]!=zz)
        {
            boo[3][2]=1;
        }
    }

    int way ;
    way =rsum-1;
    cout<<"way"<<way<<endl;
    int s=0;
    
    int sss;
    if(boo[0][3]==0&&boo[0][0]==1)
    {
        s=0;sss=ss[0];
    }
    
    else if(boo[1][0]==0&&boo[1][1]==1)
    {
        s=1;sss=ss[1];
    }
    else if(boo[2][1]==0&&boo[2][2]==1)
    {
        s=2;sss=ss[2];
    }
    
    else if(boo[3][2]==0&&boo[3][3]==1)
    {
        s=3;sss=ss[3];
    }
        /////////

    if(boo[0][3]==0&&boo[0][0]==1&&sss>ss[0])
    {
        s=0;
    }
    
    if(boo[1][0]==0&&boo[1][1]==1&&sss>ss[1])
    {
        s=1;
    }
    
    if(boo[2][1]==0&&boo[2][2]==1&&sss>ss[2])
    {
        s=2;
    }
    
    if(boo[3][2]==0&&boo[3][3]==1&&sss>ss[3])
    {
        s=3;
    }



    cout<<" s "<<s<<endl;
   


    /////////////////////////////////
    id2+="/final.path";
    //id2=url+id2;
    ofstream outfile(id2,ios::out);
    if(!outfile){cout<<"errrrrror";
        return 1;
        }
 for (int i=0;i<way;i++)
    {
        mark(s);
        
               for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            outfile<<' '<<map[i][j];
        }outfile<<endl;
    }outfile<<endl;outfile<<endl;
   outfile<<sum<<endl;
        if(boo[s][(s+1)%4]==1)
        s=change(s,1);
        else if(boo[s][(s+2)%4]==1)
        s=change(s,2);
        else if(boo[s][(s+3)%4]==1)
        s=change(s,3);
        cout<<111111111<<' '<<s<<endl;
    }
    mark(s);

/*
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cout<<' '<<intmap[0][i][j];
        }
        cout<<endl;
    }cout<<endl;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cout<<' '<<intmap[1][i][j];
        }cout<<endl;
    }cout<<endl;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cout<<' '<<intmap[2][i][j];
        }cout<<endl;
    }cout<<endl;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cout<<' '<<intmap[3][i][j];
        }cout<<endl;
    }cout<<endl;

    for(int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++)
        {
            cout<<' '<<boo[i][j];
        }cout<<endl;
    }cout<<endl;
   

   outfile<<sum/2<<endl;
outfile<<endl;outfile<<endl;
for (int z=0;z<4;z++)
{
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            outfile<<' '<<intmap[z][i][j];
        }outfile<<endl;
    }outfile<<endl;outfile<<endl;
 }   


   outfile<<endl;outfile<<endl;

*/
       for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            outfile<<' '<<map[i][j];
        }outfile<<endl;
    }outfile<<endl;outfile<<endl;
   outfile<<sum<<endl;
   
   cout<<sum<<" sum "<<endl;
   for(int i=0;i<sum;i+=2)
   {
       //cout<<a[i]<<' '<<a[i+1]<<endl;
       outfile<<i<<' '<<a[i]<<' '<<a[i+1]<<endl;
   }
   cout<<"end"<<endl;
infile.close();
outfile.close();
    
}
    return 0;
}   