#include "bits/stdc++.h"
using namespace std;
#define int long long
#define endl '\n'
int mod=1e9+7;
int mod2=998244353;
const int INF=1e9;

signed main(){
  int n;
  cin>>n;
  char a,b;
  cin>>a;
  for(int i=1;i<n;i++){
    cin>>b;
    if(a==b||(a=='F'&&b=='T'))a='T';
    else a='F';
  }
  cout<<a<<endl;
}

// `.`..`(WNNNNNNMNWWWH9rttwgHM8OtttwwVtttrrtrttrw0rtrtwrrrtrZUAOOrrrXWppHMHyZHpWHMHMkWWVHMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
// `.`.`..`(WMNMHfWH9ZtrtAdNM8ttttOwVtrrtrrtrrrrrdrrttrZkOrrrrrrXWyrtrrZWWWWMmwXWppWHHMmWHkWMMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
// .`.```_..(HMfWH9OtttwXWHBrttrOw0rttrOvrrrtrZrrRrtrrrtZHwrrrrrwwZHyrrrrZWWpWMmwWppkWHHMkHNkVWMNNNNN#NN#NN#NN#NN#NN#NN#NN#NN#NN#NNNN
// .``.. ..HNfWW9wtrrOdWHM0trttOdSrtrtwwrtrtrw0twSrtOrrrrZHwtrrrrrXwdWwrrrrXHppWNkXWpkvWH@MkHMHkWMMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
// `.`. -jMWWXXwtrttO0d@BrtrttwXVrtrrwVrrrtrtXrrd0rrXrrrrrZWyrrrrrrZXwWyZOrrvWWpWMkZHbkwrdHMMKMMNHkHMNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN
// `.`. v8Xdk9ttttrOwXM0tttrtwXwwrtrw0rrtrrtwKrrd0rrXrtrrrrZHkwrrrrrrXkVkrrrvrZHWpHHkWkwrwvVHHNWMMMMkWMNNNNNNN#NN#NN#NN#NN#NN#NN#NNNN
// .. JHZdbKOrrrtrtwWWOOttrOwSzVrOrw0rrttrrrdRrrdZrrdOrtrtrrZHkXwrrrrrZWXHwwrrrvWWWWNkWkvrrrwWM@RMMMNNmWMNNNNNNNNNNNNNNNNNNNNNNNNNNNN
// . .JGXHStttttrtwW9OrtrrrdSX0rtrdStrtrtrrwHVrrdkrrtSrrrrrrrdMyXrrrrrvXWXWmwvrrvdHWWNkWyvvvvvT@MNWM#N#MNWMMNNNNNNNNNNNNNNNNNNNNNNNNN
// (.zqHXZtrttrrOwU0trttrOdWX0OtOdRrrtrrrrrdNrrrdkrrrXOwrrrrrrdNySrrrrrwXXkUmvvwvrZHWfNkUkvwvvvdMMMRM#MMNNNkMMNNNNNN#NN#NN#NN#NN#NNNN
// (wdS0OttrtOOrwSrtttrrtwKukrrrwKrrrrrtrrwW@rrrXKrrrZkr0OrrrrrWNwkrvvrrvzXkXHwvvrvwWVVHkUyrvvvvZHMMNWMMNNNNNkWMNNNNNNNNNNNNNNNNNNNNN
// wWtrrttrrOwrwStrttrtrwWZXOrtwX0rrrttrrrXMSrrrXWrrrrXrwvrrrrvZHHXkrrrrvrzWkXNyvrvvvWWWHHWwvvvvvwHNMHRM#NNNNNMmWMMNNNNNNNNNNNNNNNNNN
// 8OtttrwZwwtwSrrttrrrwdyXwtrrdWrrtrrrrrdWH0rrrXWOrrrwRz0rrvrrrdMHWwvvrrvvXWkWHyrvvvrWWWHkHvvvvvvwWMMMNWMMNNNNNMHWMMNMNNNN#NN#NNNNNN
// wttrrdVrZrwWwtOrrrrwdWX0rrtdH0rrrtrrtwWHHrrrrXWRrrvrXXXrrvrrrvXHkSwvvrvrrXWkVHyvvvvwHVWHWRvvvvvvdHdMMMKMNNNNNNNMNkWMNNNNNNNNNNNNNM
// ttrrd0rwrOX0rrtrrtwXHXSrwrwHKrtrtrrtrdWH#rrrrdpkrrrrvHwkwvrrvrZWHXkzzvvvvwUWkpNwvrvvZHfVNHwvvvvvzXHWMNMNMNNNNNNNN#NkWMNNNNNNNNNM3>
// rrrdSrwwtXSrrtrrrwXWWKwrrrdHXrrrrrrrwWWH#vrrrvWpvrrvrdRXwvrvrvvXHWWwkvvrvvwWWKWHzwvvvXHVWWHvzzzzvzWRHMMMNHMNNNNNNNNMNkMMNNNNNN@<<>
// OOd9rw0rdKOtrtrrruXHW0rrrdH#rrrrrrrrdpWp#rrrrrXWkvrvvrWwkrvrrvwwWHpKdvvrrvvXHHfWmdwvzwWHVHWkzzzzzzwWXHMHHNWMNNNNNNNNNMNkMNNNN#z>>>
// OdSOwSwwW0rrrrtrwXNW8rrtrWWSrtrrrrrrXpHWHvrrrrXpHrrrvwZHdyvvvvvvXHpHwkvvvvvrXHHfNwXvzzwWWWKHzzzzzzzWSWHHHMMKMNNNNNNNNNNMNKMNN#>>;>
// wWwOXrwX8rtrrrrwWWpHrrrrdNNrrrrrrrrwppNWHrvrvrypWwvvrrvXKWvrvrvvZXHHkXzvvvvvwWWWWNdkvvzXHfHWkXzzzzzwWXHHHHNMHMNNNNNNNNNNNNNWMN+>>>
// R0rd0rdKrrtrtrrdWHWSrrrwWWDrrrrrrrrXpWHqWvrrrvdWbRvvrvvwWZkvvvrvvXHbHzRvvvvvvdHHpHkWwvzXWHWHHzuzzzzzXXWHHHMHMNHMNNNNNNNNNNNMNWh<>>
// wOwSrwXSrtrtrrwHWWMwrrrdNWSrrrrrrrvppWpHprrvrvddWHwvvrrvXHXwvvvrvzXWHkXzvvvvvzWWKWNdRvzzXWWHHXzzzzzzzudWHbH@HNNWMNNNNNNNNNNNNNkHe>
// rOXwwwKrrrrrrrXWHHDrrwrdHHXwrrrrrrwpWWbHWvvvrvwHHpHrvvvrXWHWwvvrwwXHkHdkvzvvvvZHHpHKWzzzwWHWHRzzzzuzzzzWHHkHHMMNWMNNNNNNNNNNNNNNKm
// rdX0OXSrrtrrrdHHWMXrrrwHWHrrrrrrrrXppqWHWkrrvvwWMHHXwwvvvZWKRvvvvrWHWHwWvzvzzzzXWKWNXRzzwXWWNHzzzzzzzzzXUHkHWMMHNWMNNNNNNNNNNNNNNN
// wSwww#rrrrrrwWWHM#vrrrd#WKvrrrrrvvXppmWMWkvvvvwXNNpNvSXzzvdHkkvvzvdWWWRXwzzzzzzdNNpMkHzzzWVHHpXzzzzzzzzdkHkHHHNMHNkMNNNNNNNNNNNNNN
// XwSwWwrrrrrrdHWWMKrvrvWHWSrvrvvvvwpppHW#HRwUUUWWMMMMMHHHHmmXHWwvvzwWHbNwRzzzzzzzWWWWHWkzzdXWWWRzzzzzzzuzWWbHHWMNMMNkMNNNNNNNNNNNNN
// 8drd#rrrrrrwWWkHMmXmywMfWXrvrrrvrwppWNWMNWvrvvwvW#MNHmdkrvvXHMMmmwzdWpM0WzzzzzzzdHHWNUHzzzWWmHHzzuzzuzuzWXbbNkHMqMHNkHNNNNNNNNNNNN
// dSwWSrrrrrrdHHHMHrrrwWMfWvvvrvrrrdppWNW#WWRvvrvvdM?WNHkXkzvvdWMHXHNmHHHkfwzzzzzzXHHpMWHkzuXWHNWXzzuzzuzzXXkkHbHMHMMMMkMNNNNNNNNNNN
// Xrd#wrrrrrrXpHWH#rrrvdMWWvrrvrvvrdppWHW#(NWwvvvvwMr~TNHmdkvzvXWMKzzzWMHKXXzzzzzzuWHbHkWKuzdWWHWkzzzuzzuuXXHkHkgHk@H@HHkMNNNNNNNNNN
// RvWDrrrrrrwHWkMW#rvvrMMfWwrvrrvvrdppWHW@~?HHuvvrvdb_~?NWkdkzzzUWMkzuuWWHWXuzwzzuzXHHHKWHuzzWW@WRuzuzzzzzduWbHHgMH@HHHMMHMNNNNNNNNN
// rdHwrrrrrrXHHWNW#vvvdMMHWkvrvrrvrdppWbWD~~?XKkrrrwMc~~~THHZHwzzWHNkvzwMRdHHzuzzzzXHHWHXNkuzdWHkWuzzuzuzzXzWkHHHMHHHkH@MMNWMNNNNNNN
// rdHvrrrrrrWkHHHW#rrrd#dNWKrvrvvrvwbpWWW$...vVkkOrtXb~~~~(WHkWkvwWWMkzzWRXkSWXzzzuwmNWHXHRuuwHMKWzzuzzzuzXzWHWHHMHHHkkMMMHHWNNNNNNN
// wW#rrvrrrwHWHMpWNrvrd@(NWWvrrrrrvvWpWXH$..._?dkkttOWl~~~~~?HHdHXXbWMkzUHXWkzzzzzzuHNk#XHHzzukHHXzuzzzuzuXuXqkMHMHMbbkHHH@HNWMNNNNN
// dH#rrrvrrdNWWNpHHwrrd@_WHWkrvvrrrrZpWXWr...__?WkWyOvN~~~~~__7HkWkbbkNkzXHZkzzzuzzzWHW#ugbXuzWWHXXuzzuzuuuzXkkHHH@MbkHMHMHMMNWMNNNN
// X@KrrvrvrXNHWHpHHHrrdb~(NWHrrrrrrrrXWXWr..`...-7HZkzvn~~~~~~~_TNyHHkHMyzXkXuzzzzuuWHW#uHkkzzWHHXuzzzzuzzuuXHkHHHMNbkHHHHHHMMNWMNNN
// WHKvvrvrvXHNMbpHmHkOwb..?HWRrwOrtrtrWKWr`.`.`..._?6dkJn~~~~~~-_~7NHMHbNkuUkzzuzzzuWHW#uHbRzuXHHXzzuuuuzuuzXHkHHMMbkkHkMkkkMMMNUMMN
// WHKrrvrrvXqHMpfHHHWkrb...vkHyOrtttttdNXr.`.J>~-((J+ggQkHXHHHmaJz7&JWHMMWkuHXzuuuzzWgHHwHkKuzXMKXuzuuzuzzuzdkHHHHHkHWMHHbkWHMMMNXM#
// Wg#rvrvrrXmHNpfHHHMMRd-.._4kfyttttllOHWr`` <udT"""7"""""TMHHMNHHMNgv4HMRXHXHwuzzzuWHHKXHkHzzXMSWzuzzuzuuzudbkHHHHkkHqHuWkWHHMMMNWM
// WHNrvrvvvXHmNppgg@MMMHr..` UkWOlllllldW$..?!     `     ` ?@MMHHMM#NMMmMkXXWkHuzuzuWNHSXHHHuuXNSWuzuuzuzuzuWkHNgMkkkMHSuWkqmqHHMNNK
// WHMkvvrvrXHHMppHHHMNMTN_``` 4kWOz====vXP` `   `        ``.HggmgM@MH###NKkkuXWHzzuXHHMzdMHHuzWNXKzuuzuzuzuuHkHHNMkkHHBuzWkHHHHuHMMM
// WHHNzvvrvwHMMppHMMMM>.#L`````?kyy====?0S``  `     ` ``...dmqqqmmHHHMMM#WRSzuzWHuzXHq#uWHHHzuWHXKzuzzuzuzuXHkHWMNkWM#uzuWHHHHSuuWM#
// WM@MkwvvrzXMMHpgHMMM[.MN.`````(HXy1???zd.``  `  `   ` dHkkqkkqkHHHHHHMMWWXzzuzwWwXHHKXMkHHuXMRXSuuuzuuzuzXHkHdHHWHHXuuwWHqHHuXzXWM
// XHHMNyrvvwdW@HpHWMHML MM[`  ` `.4kGz<<>Or```  `      `dWpbbbbbHMMbbbHHMXXuzzuzuzXWHHSXMkHHuXMSXuzzuzzuzuzWkkHWMHMSwuzzXHkHHXuzuWd#
// dHHH@NyzwwwWHMHHWMMMR dW]`` ` ```(HZx<<<4.```` `` ``  OZppfppppWfpWpK9NKXuuzuuzuXWHHudMqNHXWNuHuzzuzuzuzuHkHXMMBuuuzuuWkHHUuuuXSMS
// wWHMMMMkwwvdNpHHHM#MH-jWP``` `` ```7kI<:<h.``````` `` ,2OWVVyVVyWWWWIdMKWzuuuzzuXHHSwHHHHKXHHXSuuzuuzuzuXHHHXMXuuuuuuXHHHuzuuXSX#X
// wdWHMMMMmwXwHbpMNHMM@b.hb``````````` 7x1_(>_```````````(x7UUUV0XwvCI1dMWKXuzzuzuWHHudMkgkWbMSXuzzzuzzuzuWkHSW#zXwXuXXWHHuuXXuWXWSX
// vvXWHMMHWNkvWHbbMWMMMN_JF.```` `` `````?1_(_.`.`........(<777=<<<><<+dMXUuzuuuuWWMRwMHWMkWHHXSuuzuzuzzuXqHHXMHUXuXXHHHSuuwuXWud8uH
// mzzXWH#zHbHkXNbbWMMMMD~(_``````````````` .~_`.``.`.`.....___(<~(<<(<<dHkkuuuuuXkHHuWMkHkkkHSXXzuuzuuuuzXHHSd#uuXXWHHXuuuZuXSuqHudS
// UHzzXWSXXWbbHHHbWHMH#<~...```` ``````````````.```.` -_____<~~_<_<~~(jMWSuzuzuXWHMHXMHHHkkH#XSuzzuzuzuzuKkHXMQkWHHWUXuXXUuXUuXHuXBu
// .(Smd8wSvXbbbbHHHWHW3___.``````` `` ``````.```.```.`...._.._~~..~_~~(#WuzuuzXXkHMqMMHMkkkMUXuXzuuwuuzuXkHSWMWUUuuuXXUUuXHXXWSuXHXu
// .. JKwSvwzWkkkkHHHH5~~..```````````````````.```.````````.` .........dWSuuzzzdkHMW@MHMkkkHHXXuzuuXSuzuuWWHd#uuuXXkWSuXXWUXXHUXWHuuu
// .`(HXSzzzzwWbkWHNHr_...``````````````````.```````.```````.`.`..`.-.(HKuzzuuwHHMNMHHMkkkHHuZuuzuuXuuuuXkHWMHHHUUuXXXWHXXHHUuXW8uuuu
// .-MXWwzzzuzXkHHMHHN-.`````````` ````````````.`.````.``.```.`.`....-dXUXuzuXHWHMMHHBWHMMMSZuzuuzXXzuuXHHMHMHkHHHHHHHWHHSuXkHWSuuuuX
// (#XKzzzzzuzuWHHkWHHp ``.````````````````````````.````````.....-((-(NSXuzzXHW@D:~`(/1- .kXuzuuzXSuuzXXkHWMHHHHHHHHMWuuuQXUXWuuuXuXH
// MXWzuzzzzzuXHHbHNMMMt`.```````````````````````````.`.` ..-J7"!``  XKuzzuXHHM9;/<-.J-u!JXXuuzuXWuuuuXHHH#WMNHmkkkuXXkWUXXWXXuuuXqHH
// XWzzzzuzzwXHHHH#"````<.````````````````````.``.`...-c"7``` ` `  `(BzuuuXmHH8<!(- ?_!`jWUuzuuuWuuuzXWHNH> ..7WHHqHmQkWWXXuuuuuXWqHH
// SwuzzzXuwXHNHY``  ``  <,`.`````````````` `` ..J7=``` ` ` `` ````.#zuzXXHHH$~`` ```(_(HSuuuzuXSuzuuXHHWCi(` ._ ?WggHHHHWkkkkWHHHHMH
// zzzuzuzwWHMY!`  `   ` `(&.```````````` ..J7^ `` `  `  `   ` `. .HXuuXWHW#!` ` ```` (WUuzzuXXSzuuudHHXY$. : (..``.THHkqkHHHgHHMHkkk
// zzzzzzXHWK``  ` `` ` ` ` TJ.``````..J7=````    ` `  ` ` `` ` `.8zuXXHHW=`   ``  ..(XSuuuuuXWuuuuXHWH5~~` .`_?_,-``.TMMMMMMHkkqqHHH
// zzuuzdHHkN ` ` `  ``  ` ``(Wm,.(J7!```  `  ``` `` `` ` ` ``` .SzuXWHHY `` .._~<~~(dSuuuzzXHuuuuXHWHD::?C._.( -`(!_1 ,WHqHHHmqHHHHN
// zuzXXHHkHM;`  ` ` ` ``  ` .;jY= ` .``_``  `  `  `  ` `` ` `.dXuXWm@^ .._~_.~~~~~(d0uuzuuXHUuuuXHWH5:::::::_.<&._4r?_.;WMMM@MMY"<!`
// zzXHHHHMHMb`` `` ` `` `` .J!  ` ..`_~  ` ` ` `` `   `  ``.JXXXHY! .__.....~.~~~-d0wuzuXXHSuuuXWWH$::::;:::;:+- ~`(.i +HqHHkkHL..`.
// XWHHHMMHMHM; `  ` `   ` ._`` ...(:.=_` `  ` `  ` ```` .-dVT7^``````......~~~~~_jWuuuuuXHSuzuXHHH3<;:::::;;j<+z ``` -dHNkkMqkkN..``
// HHHMMHHHHNMN.``  ` `  `!`z(. ~..~ ! . ` ``  ` ` ` ..gHr``````````........~~~~_jWuuuuuXkSuuuXHWHC:;::;;:::+v>:((J<!(WHHMkkHNqkM;`..
// HMMkkHHHHM9?b ``  ` `  ``     .``. `  ` ` `  ``` 4HkkkH,  ``````.`......~~~~_+KuuuzuXHSuuuXHHK<(::::::<;<J+g9>::;<  .4NkkqMHqH]..`
// MHkHHHMM$<<:?L` `` ` `  ` ``.` `  !``  ` ` ` `  ` ?HbkkHx``````.`..`...~~~~_jKuuuuuXHSuuuqMHD<:<;:<++ddNMB3:;::;:<` `,HkkqH@HH].``
// kkHHkHY``` (;?h`` ` ` ``  ````  ` ` ` ` ` ` ` ` ```.4XWbHx```..`......~~~~_gKuuuuXWH0uuuXHH3:;++1z<jgMB3<::::::::~` `jMkqkHMHHF.`.
// kHHHH=` . ` _<?L  ` `  ` `    `  ` ` ` ` ` ` `  ` `  ?kwWHp .`.......~_~~(dKuuuuXWHUuuXWH9++z1<;+jWB3::::;;;::;:;_`` MNkqkqMNMF..`
// HHk@!.  ` ` ` ~?L  ` ` `` ` `` `` ` ` ` `  ` ` `   `  -WuXHh..`.....~~~~(dWuuuXXkHUuuXHH9>:<:++YY<:;::::;:::::;:::+.``?HHkHHHM>`.`

