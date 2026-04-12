A, B, C, X, Y = map(int,input().split())

def best_pizza_cost(ln, hn):
    if ln == X: lp = A
    else: lp = B

    if hn == Y: hp = B
    else: hp = A

    fnp = lp * ln + hp * ln
    fhp = C * ln * 2

    left = hn-ln
    snp = hp * left
    shp = C * left * 2
    #print(fnp, fhp, snp, shp)
    return min(fnp, fhp) + min(snp, shp)

print(best_pizza_cost(min(X, Y), max(X, Y)))