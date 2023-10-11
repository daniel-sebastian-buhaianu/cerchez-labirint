#include <fstream>

#define DMAX 100
#define ND 4

using namespace std;

ifstream fin("labirint.in");
ofstream fout("labirint.out");

struct pozitie { int x, y; };

int dl[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int a[DMAX+2][DMAX+2];
pozitie coada[DMAX*DMAX];

int main()
{
	int n, m, i, j, inc, sf, k;
	char c;
	pozitie ps, pc, p, v;

	fin >> n >> m;

	// citesc newline
	fin.get(c);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			// citesc '#', 'S', 'C' sau ' '
			fin.get(c);

			if (c == '#')
			{
				a[i][j] = -1; // marchez obstacolul
			}

			if (c == 'S')
			{
				// retin pozitia soricelului
				ps.x = i;
				ps.y = j;
			}

			if (c == 'C')
			{
				// retin pozitia cascavalului
				pc.x = i;
				pc.y = j;
			}
		}

		// citesc newline
		fin.get(c);
	}

	fin.close();

	// bordez matricea
	for (i = 0; i <= m+1; i++)
	{
		a[0][i] = a[n+1][i] = -1;
	}

	for (i = 0; i <= n+1; i++)
	{
		a[i][0] = a[i][m+1] = -1;
	}

	// aplic algoritmul lui Lee pentru a calcula lungimea minima
	// de la pozitia soricelului pana la pozitia bucatei de cascaval
	inc = sf = 0, coada[sf] = ps;

	a[ps.x][ps.y] = 1;

	while (inc <= sf && a[pc.x][pc.y] == 0)
	{
		p = coada[inc++];

		for (k = 0; k < ND; k++)
		{
			v.x = p.x + dl[k];
			v.y = p.y + dc[k];

			if (a[v.x][v.y] == 0)
			{
				a[v.x][v.y] = 1 + a[p.x][p.y];

				coada[++sf] = v;
			}
		}
	}
	
	// afisez lungimea minima
	fout << a[pc.x][pc.y] << '\n';
			
	fout.close();

	return 0;
}
