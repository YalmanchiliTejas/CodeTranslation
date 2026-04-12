X, Y, Z = map(int, input().split())
s = X - (X//(Y+Z))*(Y+Z)
print(X//(Y+Z) if s >= Z else X//(Y+Z)-1)