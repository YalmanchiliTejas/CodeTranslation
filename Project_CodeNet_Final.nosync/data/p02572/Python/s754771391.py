n = int(input())
a = list(map(int, input().split()))

sum_ = 0
temp = 0
for i in range(len(a)-1):
    temp += a[-i-1]
    sum_ += temp * a[-i-2]

print(sum_%(10**9 + 7))