a,b,c,x,y = map(int, input().split())
one = max(x,y) * 2 * c
two = min(x,y) * 2 * c
if x >= y:
    two += abs(x-y) * a
else:
    two += abs(x-y) * b
three = x * a + y * b
print(min(one, two, three))