modulo = 10 ** 9 + 7

k = str(input())
digits = len(k)
d = int(input())

matrix = []

for i in range(10005):
    matrix.append([[0, 0] for j in range(d)])
    
matrix[0][0][1] = 1

for i, digit in enumerate(k):
    digit = int(digit)
    #print(digit)
    
    for j in range(d):
        
        for k in range(10):
            aux = (j - k) % d
            matrix[i+1][j][0] = (matrix[i+1][j][0] + matrix[i][aux][0]) % modulo
        aux = (j - digit) % d
        matrix[i+1][j][1] = matrix[i+1][j][1] + matrix[i][aux][1]
        
        for k in range(digit):
            aux = (j - k) % d
            matrix[i+1][j][0] = (matrix[i+1][j][0] + matrix[i][aux][1]) % modulo
            
result = (matrix[digits][0][0] + matrix[digits][0][1] - 1) % modulo
print(result, end='\n')