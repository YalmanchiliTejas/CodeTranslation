
def cmd():
    A, B, C, X, Y = map(int, input().split())
    buyAB = A*X + B*Y
    if X == Y:
        buyminC = C*2*min(X,Y)
    elif X > Y:
        buyminC = C*2*min(X,Y) + A*(X-Y)
    else:
        buyminC = C*2*min(X,Y) + B*(Y-X)
    buymaxC = C*2*max(X,Y)
    #print("buyAB:{}, buyminC:{}, buymaxC:{}".format(buyAB, buyminC, buymaxC))
    print(min(buyAB, buyminC, buymaxC))

if __name__ == "__main__":
    cmd()
