str = list(input())
A = str[0]
B = str[1]
C = str[2]

ans = "No"
if A != B:
    ans = "Yes"
elif A != C:
    ans = "Yes"
elif B != C:
    ans = "Yes"


print(ans)
