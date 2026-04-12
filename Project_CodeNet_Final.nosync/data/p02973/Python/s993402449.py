from bisect import bisect_right as f
N=int(input())
X=[-1]*N
for _ in X:a=int(input());X[f(X,a-1)-1]=a
print(N-X.count(-1))