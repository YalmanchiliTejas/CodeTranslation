N = int(input())
inline = list(map(int,input().split()))
so = inline.copy()
so.sort()


left = so[int(N/2)-1]
right = so[int(N/2)]


for i in range(N):
    if inline[i] <= left:
        print(right)
    else:
        print(left)