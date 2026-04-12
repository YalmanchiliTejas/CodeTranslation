N = int(input())
H = list(map(int, input().split()))

_count=1
max_height=H[0]

for i in range(1,N):
    if max_height <= H[i]:
        _count +=1
        max_height = H[i]
print(_count)
