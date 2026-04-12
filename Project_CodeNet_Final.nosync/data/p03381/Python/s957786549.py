N = int(input())
X = [int(i) for i in input().split()]
a = X.copy()
a.sort()
a_l = a[N // 2 - 1]
a_r = a[N // 2]
for i in range(N):
    if X[i] <= a_l:
        print(a_r)
    else:
        print(a_l) 

