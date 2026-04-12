def f(s):
    return eval(s)
    
def g(s):
    ret = ord(s[0])-48
    i = 1
    while i < len(s):
        if s[i] == '+':
            ret += ord(s[i+1])-48
        else:
            ret *= ord(s[i+1])-48
        i += 2
    return ret

s = input()
n = int(input())
f1, f2 = (n == f(s)), (n == g(s))
if f1 and f2:
    print("U")
elif f1:
    print("M")
elif f2:
    print("L")
else:
    print("I")
