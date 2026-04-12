input()
print((lambda S,K:''.join(['*',i][i==S[K-1]]for i in S))(input(),int(input())))