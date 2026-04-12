words = lambda t : list(map(t, input().split()))
a,b = words(int)
if a == b:
    print("Yes")
else:
    print("No")
