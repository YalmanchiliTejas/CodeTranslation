r, g, b = map(str, input().split())
ans = r + g + b
# print(ans)
ans_i = int(ans)
 
if ans_i % 4 == 0:
    print('YES')
else:
    print('NO')