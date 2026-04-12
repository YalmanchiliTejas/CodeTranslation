S = input()
# バリエーションが1種類全文重複してるならNO
if len(set(S)) == 1:
    print('No')
else:
    print('Yes')