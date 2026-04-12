N = int(input())
X = list(map(int, input().split()))

x = sorted(X)
ml = x[N//2 - 1]
mr = x[N//2]

for x in X:
    if x <= ml:
        print(mr)
    else:
        print(ml)