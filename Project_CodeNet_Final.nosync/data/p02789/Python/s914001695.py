def get(text,n):
    ans = [""]*n
    i = 0
    for x in text:
        if x==" ":
            i = i + 1
        ans[i] = ans[i]+x
    return ans

text = input()

if int(get(text,2)[0]) == int(get(text,2)[1]):
    print("Yes")
else:
    print("No")
