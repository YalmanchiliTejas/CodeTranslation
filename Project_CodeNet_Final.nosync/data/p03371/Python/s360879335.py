A, B, C, X, Y = map(int, input().split())

# strategy 1: buy only AB                                                                                                                                                                                   

a1 = 2 * C * max(X, Y)

# strategy 2: buy only A and B                                                                                                                                                                              
a2 = A * X + B * Y

# strategy 3: buy AB until one is satisfied                                                                                                                                                                 
a3 = 2 * C * min(X, Y) + A * (X-min(X, Y)) + B * (Y-min(X, Y))

print(min(a1, a2, a3))

