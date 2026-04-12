def A(x):
    d = "Yes"
    f = "No"
    if x<30:
        return f
    else:
        return d
x = int(input())
l = A(x)
print(l)