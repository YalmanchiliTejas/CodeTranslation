s = input()
f = lambda x,y : x.count("A") == y
print("No" if f(s, 0) or f(s, 3) else "Yes")