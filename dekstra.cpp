#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int n, m;
int nx, ny, kx, ky;
vector <int> a;
vector <int> p;
vector <vector <int>> g;
int yu = 10000;
void decstra(){
    a[nx*m + ny] = 0;
    vector <pair<int, int>> id = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    set <pair<int, int>> se;
    se.insert({0, nx*m + ny});
    
    while (se.size() != 0) {
        pair<int, int> ver = *se.begin();
        se.erase(se.begin());
        int x = ver.ss/m;
        int y = ver.ss%m;
        for (int i = 0; i < 4; i ++) {
            if (id[i].ff + x < 0 ||
                id[i].ff + x > n-1 ||
                id[i].ss + y < 0 ||
                id[i].ss + y > m - 1) continue;
            if (a[x*m + y + id[i].ff*m + id[i].ss] > a[x*m + y] + 1
                && g[id[i].ff + x][id[i].ss + y] == 1) {
                se.insert({a[x*m + y] + 1, x*m + y + id[i].ff*m + id[i].ss});
                a[x*m + y + id[i].ff*m + id[i].ss] = a[x*m + y] + 1;
                p[x*m + y + id[i].ff*m + id[i].ss] = x*m + y;
            }
        }
    }
}
int main(){

     std::string line;
 
    std::ifstream in("hello.txt"); // окрываем файл для чтения
    in >> n >> m;
    a.resize(n*m, yu);
    p.resize(n*m, -1);
    g.resize(n, vector <int> (m));
    for (int i = 0; i < n; i ++) {
        string s;
        in >> s;
        for (int j = 0; j < m ; j ++) {
            if (s[j] == '#') {
                g[i][j] = 0;
            } else {
                g[i][j] = 1;
            }
        }
    }
    in >> nx >> ny >> kx >> ky;
    in.close();     // закрываем файл
    decstra();
    int tt = kx*m + ky;
    vector <int> ans;
    while (tt != nx*m + ny) {
        ans.push_back(tt);
        tt = p[tt];
    }
    cout << "-----------------------\n";
    cout << nx << " " << ny << "\n";
    for (int i = ans.size() - 1; i > -1; i--) {
        cout << ans[i]/m << " " << ans[i]%m<< "\n";
    }
    cout << a[kx*m + ky] << "\n";
    return 0;
}
