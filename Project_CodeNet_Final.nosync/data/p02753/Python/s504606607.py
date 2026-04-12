S = input()
a, b = [False, False]

for s in S:
    if s == "A":
        a = True
    else:
        b = True

ans = "No"
if a and b:
    ans = "Yes"

print(ans)
