N, X = map(int, input().split())

rayers = [0] * (N+1)
rayers[0] = 1
Ps = [0] * (N+1)
Ps[0] = 1
for i in range(1,N+1):
    rayers[i] = 3 + 2*rayers[i-1] # B{L-1}P{L-1}B
    Ps[i] = 1 + 2*Ps[i-1] # そのレベルのPの数は前のレベルの数*2＋1こ

def solve(N,X):
    if N == 0:
        return 0 if X <= 0 else 1

    if X <= rayers[N-1]+1:
        # 食べる枚数が、Nレベルバーガーの中心より手前の時、その一レベル下のバーガーから底のBを一枚除いて食べるのと同じ
        return solve(N-1, X-1)
    elif X == rayers[N-1]+2:
        # Nレベルバーガーのちょうど真ん中まで食べるとき
        return Ps[N-1] + 1 
    elif X > rayers[N-1]+2:
        # 真ん中より先の方まで食べるとき
        return Ps[N-1] + 1 + solve(N-1, X - rayers[N-1] - 2)

print(solve(N,X))
