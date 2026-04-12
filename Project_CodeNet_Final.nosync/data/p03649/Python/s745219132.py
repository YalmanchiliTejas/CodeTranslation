# ARC079E
n = int(input())
a = list(map(int, input().split()))

def sub(n, a):
    # aを現時点で必要なだけ叩いて、その回数と終わったあとの状態
    c = 0
    nums = [0] * n
    for i,num in enumerate(a):
        if num> n-1:
            v = (num - (n-1)) // n + bool((num - (n-1)) % n)
            a[i] = num - v*n
            nums[i] -= v
            c += v
    return c, [c+num+num2 for num,num2 in zip(a, nums)]

count = 0
while max(a)>=n:
    c, a = sub(n, a)
    count += c
print(count)