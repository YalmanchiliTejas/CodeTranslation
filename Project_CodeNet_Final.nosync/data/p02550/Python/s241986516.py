n, x, m = map(int, input().split())

def f(x, m):
    return (x**2) % m

a = [x]
end = 0
for i in range(1, n):
    tmp = f(a[i-1], m)
    if tmp in a:
        end = i
        break
    a.append(tmp)
if end == 0:
    print(sum(a[:n]))
    exit()
start = -1
for idx, v in enumerate(a):
    if v == tmp:
        start = idx
# print(end-start)
# print(a, start, end)
length = end - start
set_sum = sum(a[start:end+1])
# print(set_sum)
if n-1 < start:
    print(sum(a[:n]))
    exit()
else:
    ans = sum(a[:start])
    plus = n - start
    num = plus // length
    yozyo = plus % length
    ans += (set_sum*num)
    ans += sum(a[start:start+yozyo])
    print(ans)
    exit()