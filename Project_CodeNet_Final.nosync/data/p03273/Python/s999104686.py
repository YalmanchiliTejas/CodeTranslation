H, W = map(int, input().split())
A = []
answer = []
for _ in range(H):
    a = list(input())
    if("#" in a): A.append(a)


for a in list(zip(*A)):
    if("#" in a): answer.append(a)

for result in list(zip(*answer)): print("".join(result))