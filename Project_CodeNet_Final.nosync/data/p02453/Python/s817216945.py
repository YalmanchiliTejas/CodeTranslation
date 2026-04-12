import bisect

n = int(input())
a = sorted(list(map(int,input().split())))
a.append(1e20)

for i in range(int(input())):
    print(min(n,bisect.bisect_left(a,int(input()))))
