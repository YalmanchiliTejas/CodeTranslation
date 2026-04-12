# ABC124B

n = int(input())
h = list(map(int, input().split()))
while True:
    removed = False
    for i in range(1, n):
        if i < len(h) and h[i-1] > h[i]:
            # print(f"removed {h[i]}")
            removed = True
            h.pop(i)
    if removed == False:
        break
print(len(h))
