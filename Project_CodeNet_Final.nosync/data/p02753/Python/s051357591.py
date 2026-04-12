S = input()
seen = set()

for s in S:
    seen.add(s)

print( 'Yes' if len(seen) == 2 else 'No' )
