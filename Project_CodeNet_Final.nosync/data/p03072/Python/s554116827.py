N = int(input())
H = list(map(int,input().split()))

_max = 0
cnt = 0
for i in H:
    if i >= _max:
       cnt += 1
       _max = i

print(cnt)