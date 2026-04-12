n = int(input())

for i in range(n):
    s = input()
    dic = {chr(c): 0 for c in range(ord('a'), ord('z') + 1)}
    for c in s:
        dic[c] += 1
    # 最初の1周
    if i == 0:
        ans = {chr(c): 0 for c in range(ord('a'), ord('z') + 1)}
        for k, v in dic.items():
            ans[k] = v
    # 以外
    else:
        for k, v in dic.items():
            ans[k] = min(ans[k], v)

for k,v in ans.items():
    if v != 0:
        print(k*v,end="")

print()
