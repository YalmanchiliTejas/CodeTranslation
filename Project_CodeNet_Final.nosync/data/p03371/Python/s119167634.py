a, b, c, x, y = map(int, input().split())

ans = 5000*(10**5)*2
for i in range(max(x, y)+1):
    tmp_ans = i*2*c
    if x > i:
        tmp_ans += (x-i)*a
    if y > i:
        tmp_ans += (y-i)*b
    ans = min(ans, tmp_ans)

print(ans)
