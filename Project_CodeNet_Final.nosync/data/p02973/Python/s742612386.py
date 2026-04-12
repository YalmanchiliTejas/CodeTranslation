from bisect import bisect_right
N=int(input())
X=[-1]*N
for _ in X:a=int(input());X[bisect_right(X,a-1)-1]=a
print(N-X.count(-1))