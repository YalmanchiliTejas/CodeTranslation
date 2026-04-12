#ABC095_C
A,B,C,X,Y= map(int, input().split())
#AピザがA円、BピザがB円、ABのハーフハーフがC円。
#用意したいピザはAがX枚、BがY枚。
#Aピザをi枚買うとすると、ハーフハーフは2*(X-i)枚必要。
#このとき、Bピザの購入すべき枚数は

price_min = 1000000000
#初期値に注意する。どんどん安い値段が見つかるたびに更新したいのだから、
#初期値は十分大きくしておかないと、いつまでたっても最安値は更新されない

#Aピザをi枚買うとすると、iはi<=Xを満たす。
for i in range(X+1):
    #この時点ですでにBピザはX-i枚分ある。残りのピザをBピザとハーフピザで用意する。
    #この時点ですでにBピザが足りているなら、これ以上購入する必要はない。
    if Y <= X-i:
        price = i*A + 2*(X-i)*C
    #まだ足りないなら、残りY-（X-i）枚を用意する必要がある。
    #どちらを購入するかは、BとCの価格のうち、安いほうとすればよい。
    else:
        price = i*A + 2*(X-i)*C + min((Y-(X-i))*B,2*(Y-(X-i))*C)
    #print("Price now:", price)
    if price_min > price:
            #print("price_min",price_min,",price:",price)
            price_min = price
            #print("price_min changed to", price_min)
print(price_min)