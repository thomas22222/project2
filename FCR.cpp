#include<iostream>
#include<string>
#include<fstream>

using namespace std;
int v [999][999];

int main()
{
    string id;
    id="floor.data";

    ofstream outfile(id,ios::out);
    if(!outfile){cout<<"errrrrror";
        return 1;
        }
    
    for (int i=0;i<499;i++)
    {
        for (int j=0;j<499;j++)
        {
            if(i==j)
            v[i][j]=1;
            else if(i+j==498)
            v[i][j]=1;
            else 
            v[i][j]=0;
        }
        
    }
    v[249][249]='R';
    v[0][0]=0;
    v[498][0]=0;
    v[0][498]=0;
    v[498][498]=0;
    outfile<<499<<' '<<499<<' '<<996;
    for (int i=0;i<499;i++)
    {
        outfile<<endl;
        for (int j=0;j<499;j++)
        {
            if(j!=498)
            outfile<<v[i][j]<<' ';
            else 
            outfile<<v[i][j];
        }
        
    }
 
    return 0;
}
