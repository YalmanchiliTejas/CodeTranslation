N,X = map(int,input().split())
#バーガーは2*cnt+3、パティは2*cnt+1
#レベルNバーガー&パティの総数リスト　indexは[N-1]
numB = [1]
numP = [1]
for i in range(50):
    numB.append(numB[i]*2+3)
    numP.append(numP[i]*2+1)
#二分探索の作成
L = 0; R = numB[N]+1
K = N   #Kは今調べているバーガー
ans = 0
while K>0:
    Mid = (L+R)//2
    if X == L+1:
        break
    if L+2 <= X <= Mid-1:
        K -= 1
        L += 1; R = Mid
        continue
    if X == Mid:
        ans += numP[K-1]+1
        break
    if Mid+1 <= X <= R-2:
        ans += numP[K-1]+1
        K -= 1
        L = Mid; R -= 1
        continue
    if X == R-1:
        ans += numP[K]
        break
else:
    ans += 1
print(ans)

