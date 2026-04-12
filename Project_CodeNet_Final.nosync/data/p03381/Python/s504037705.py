n = int(input())
x = list(map(int, input().split()))
x_ = sorted(x)
a = x_[int(len(x)/2)-1]
b = x_[int(len(x)/2)]

for i in range(n):
    if x[i]>=b:
        print(a)
    else:
        print(b)