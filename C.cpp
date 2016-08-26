#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define f first
#define s second
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int y,a,g;
        cin>>y>>a>>g;
        int cc=0;
        while(g--){
            int m;cin>>m;
            while(m--){
                int tmp;cin>>tmp;
                if(y-tmp>=a)cc++;
            }
        }
        cout<<cc<<endl;
    }
}
