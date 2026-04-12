A, B, C, X, Y = map(int, input().split())

prise = A*X + B*Y
x = X
y = Y
anset = set()
anset.add(prise)
while max(x, y)>0:
    if x > 0:
        prise -= A
    if y > 0:
        prise -= B
    prise += C * 2
    anset.add(prise)

    x -= 1
    y -= 1

print(min(anset))