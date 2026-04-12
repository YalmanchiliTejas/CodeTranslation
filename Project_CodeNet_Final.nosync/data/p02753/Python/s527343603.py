#先頭文字が繰り返されるか否かで判定。三項演算子も使用。
S = input()
print('No' if S == (S[0] * len(S)) else 'Yes')