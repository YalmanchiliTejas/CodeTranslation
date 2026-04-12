N = int(input())
A = [int(x) for x in input().split()]

def check(x):
    work = 0
    for a in A:
        work += a
        if work < x:
            return 0
        work -= x
    return 1

ans = 0
for i in range(101):
    if check(i):
        ans = i
print(ans)
    

