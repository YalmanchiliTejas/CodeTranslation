# 単体ピザで埋めてからハーフピザを買うか、
# ハーフピザで埋めてから単体ピザを足すのが良いはず。

A, B, C, X, Y = map(int, input().split())
a, b = X, Y
est = []

#ハーフ埋め
esth = C * min(X, Y) * 2
a -= min(X,Y)
b -= min(X,Y)
esth += A * a + B * b
est.append(esth)

#全ハーフ
a, b = X, Y
estah = C * max(X, Y) * 2
est.append(estah)

#全単品
a, b = X, Y
estfa = A * a + B * b
est.append(estfa)

print(min(est))

