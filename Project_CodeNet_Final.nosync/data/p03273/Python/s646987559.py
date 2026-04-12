h,w=map(int,input().split())
for i in zip(*[i for i in zip(*[i for i in [input() for i in range(h)] if '#' in i]) if '#' in i]):
    print(''.join(i))

#1 1番内側の処理 [input() for i in range(h)] で1行ごとに文字列としてリストに格納
#2 [i for i in [#1] if '#' in i] で内側のリストに格納した要素で"#"を含むものを i に格納する (ここはリストの展開)
#3 [i for i in zip(#2) if "#" in i] #2で作成したリストを要素の先頭、2番目...のように
#縦で構成された要素を集めたリストに作り替える、この際"#"を含まないものは除かれる(ifの部分)
#4 [i for i in zip(#3)] を行うことによって縦横の入れ替わったリストをもう一度入れ替える(元に戻す)
