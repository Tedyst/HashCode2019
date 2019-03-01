#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.in");
ofstream fout ("output.out");
bool v[80001][1000];
char taguri[100000][10];
int luat[1000];
bool luatpoza[80001];
int nrtaguri=0,n;
bool orizontal[80001];
vector<int> sol;
int tag() {
    char s[10]= {0};
    bool ok=true;
    int tag=0;
    fin>>s;
    for(int i=0; i<=nrtaguri; i++)
        if(strcmp(taguri[i],s)==0) {
            ok=false;
            tag=i;
            break;
        }
    if(ok) {
        nrtaguri++;
        tag=nrtaguri;
        strcpy(taguri[nrtaguri],s);
    }
    return tag;
}
int get_max(int& id,int& maxim) {
    int nr=0;
    for(int i=0; i<=nrtaguri; i++)
        if(luat[i]==0) {
            int nr=0;
            for(int j=0; j<n; j++)
                if(v[j][i]==1)
                    nr++;
            if(maxim<nr) {
                maxim=nr;
                id=i;
            }
        }
    luat[id]=1;
    return id;
}
void add(int id) {
    for(int i=0; i<=n; i++)
        if(v[i][id]==1&&luatpoza[i]==0) {
            // cout<<i<<'\n';
            sol.push_back(i);
            luatpoza[i]=1;
        }
}
int main() {
    int nr;
    fin>>n;
    char c;
    for(int i=0; i<n; i++) {
        fin>>c;
        if(c=='H')
            orizontal[i]=0;
        else
            orizontal[i]=1;
        fin>>nr;
        for(int j=1; j<=nr; j++) {
            int t=tag();
            v[i][t]=1;
        }
    }
    cout<<nrtaguri<<'\n';
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<=nrtaguri; j++)
    //         cout<<v[i][j];
    //     cout<<'\n';
    // }
    int ramas=n;
    for(int i=0; i<=ramas; i++) {
        int id=0,maxim=0;
        get_max(id,maxim);
        ramas=ramas-maxim;
        add(id);
    }
    fout<<sol.size()<<'\n';
    for(int i=0; i<sol.size(); i++)
        fout<<sol[i]<<'\n';
    return 0;
}