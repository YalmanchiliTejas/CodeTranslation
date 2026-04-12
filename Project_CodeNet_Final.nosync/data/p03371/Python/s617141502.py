A, B, C, X, Y = map(lambda x: int(x), raw_input().split())


"""                                                                                                                                                                   
                                                                                                                                                                      
1500 2000 1600 3 2                                                                                                                                                    
                                                                                                                                                                      
A * 3 + B * 2                         = 8500                                                                                                                          
                                                                                                                                                                      
2C + A*2 + B * 1 = 3200 + 4000 + 1600 = 8800                                                                                                                          
4C + A*1 + B * 0 = 6400 + 1500        = 7900                                                                                                                          
6C                                    = 9600                                                                                                                          
                                                                                                                                                                      
"""

acc = []

maxC = 2 * max(X,Y) + 2

for i in range(maxC):
    x=i
    if x % 2 == 0:
        Csize = x/2
        remXsize = X - Csize
        remYsize = Y - Csize
        acc.append( C * x + A * max(remXsize,0) + B * max(remYsize,0) )

#print acc                                                                                                                                                            
print min(acc)