N = int(input())
H = list(map(int, input().split()))

i = 0
ans = 1
Front = []

while i <= N-2:
    Front.append(H[i])
    if H[i+1] - max(Front) >= 0:
            ans = ans + 1
    i = i+1

print(ans)
