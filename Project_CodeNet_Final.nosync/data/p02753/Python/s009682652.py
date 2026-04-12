s = str(input())
lists = list(s)

if len(set(lists)) == 1:
    print("No")
else:
    print("Yes")