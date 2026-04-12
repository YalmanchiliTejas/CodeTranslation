n,x = map(int,input().split())

li = [1]
li2 = [1]

for i in range(n):
    li.append(3+2*li[-1])
    li2.append(1+2*li2[-1])

ans = 0

for i in range(n):
    x -= 1
    if x >= li[-2-i]:
        x -= li[-2-i]
        ans += li2[-2-i]
    else:
        continue
    if x > 0:
        x -= 1
        ans += 1
    else:
        break
    if x >= li[-2-i]:
        x -= li[-2-i]
        ans += li2[-2-i]
    else:
        continue

print(ans)
