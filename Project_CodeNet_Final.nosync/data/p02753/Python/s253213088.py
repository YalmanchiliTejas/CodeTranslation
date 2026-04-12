s = input()
dic = []

for t in s:
    if t not in dic:
        dic += t

ans = "No"
if len(dic) > 1:
    ans = "Yes"

print(ans)
