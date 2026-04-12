#新しい値が最小なら追加，そうでなければそれを超えない最大の値を書き換え
#降順なので，10**10から引くことで逆転させておく
#→新しい値が最大なら追加，そうでなければそれを超える最小の値を書き換え
import bisect

N=int(input())
A=[10**10-int(input()) for _ in range(N)]

b=[]
b.append(A[0])

for i in range(1,N):
    index=bisect.bisect_right(b,A[i])
    if index==len(b):
        b.append(A[i])
    else:
        b[index]=A[i]
print(len(b))