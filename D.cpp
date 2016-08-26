#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define MAX 40
#define all(v) v.begin(),v.end()
#define INF 1<<20
using namespace std;
#define sol vector<vector<int>>
string pb[MAX][MAX] ;
 struct coord{
    int x;
    int y;
    int z;
    inline coord operator=(coord a) {
        x=a.x;
        y=a.y;
        z=a.z;
        return a;
    }

    inline coord operator+(coord a) {
        return {a.x+x,a.y+y,a.z+z};
    }

    inline bool operator==(coord a) {
       if (a.x==x && a.y== y && a.z ==z)
          return true;
       else
          return false;
    }
    inline bool operator< (coord a){
        if (a.x>x || a.y>y || a.z>z)
          return true;
       else
          return false;
    }
} ;

coord P[]={{0,1,0},{0,0,1},{0,-1,0},{0,0,-1},{1,0,0},{-1,0,0}};

bool valid(coord i,int L,int R,int C){
    coord u = {0,0,0},v={L-1,R-1,C-1};
    if(i<u || v<i)return false;
    if(pb[i.x][i.y][i.z]=='X')return false;
    return true;
}
void solve(vector<sol> &ans,coord s,coord e,int L,int R,int C){
    queue<coord> Q;
    vector<sol> visited(L,vector<vector<int>>(R,vector<int>(C,0)));
   visited[s.x][s.y][s.z]=1;
   ans[s.x][s.y][s.z]=0;
   Q.push(s);
   while(!Q.empty())
   {
      coord p = Q.front();
      Q.pop();
      for(auto i:P){
        coord u=i+p;
        if(!valid(u,L,R,C))
            continue;
        ans[u.x][u.y][u.z]=min(ans[u.x][u.y][u.z],1+ans[p.x][p.y][p.z]);
        if(visited[u.x][u.y][u.z]==0){
           visited[u.x][u.y][u.z]=1;
            Q.push(u);
        }
      }

   }
}
int main(){
    int tc;cin>>tc;
    while(tc--){
        int L,R,C;
        coord s,e;
        scanf("%d-%d-%d",&L,&R,&C);
        for(int i=0;i<L;i++)for(int j=0;j<R;j++){
            string tmp="";
            while(getline(cin,tmp))if(tmp!="")break;
            pb[i][j]=tmp;
            for(int k=0;k<pb[i][j].size();k++)
                if(pb[i][j][k]=='i')
                    s={i,j,k};
                else if(pb[i][j][k]=='o')
                    e={i,j,k};

        }
        vector<sol> ans(L,vector<vector<int>>(R,vector<int>(C,INF)));
        solve(ans,s,e,L,R,C);
        if(ans[e.x][e.y][e.z]==INF)cout<<"Opps!"<<endl;
            else cout<<ans[e.x][e.y][e.z]<<endl;
    }
    return 0;
}
