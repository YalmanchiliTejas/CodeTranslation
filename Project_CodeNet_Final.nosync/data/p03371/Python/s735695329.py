A,B,C,X,Y = [int(x) for x in input().split()]

def calc_cost(max_a,max_b):
    need_ab = max(X-max_a, Y-max_b)
    a = max(X - need_ab, 0)
    b = max(Y - need_ab, 0)
    return A*a + B*b + C*(2*need_ab)

print(min([calc_cost(x,y) for x in [0,X] for y in [0,Y]]))