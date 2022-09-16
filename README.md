# Blokowanie podejrzanych domen CERT przez DNS Windows Server

Przedstawiony skrypt automatycznie pobiera listę podejrzanych domen opracowanych przez CERT Polska z adresu <http://hole.cert.pl/domains/domains.txt> oraz na jej podstawie tworzy i wykonuje skrypt dodający domeny do lokalnego serwera DNS. Skrypt tworzy strefy wyszukiwania do przodu dla każdej domeny i tworzy rekordy A dla domeny oraz prefixu WWW wskazujące na <http://hole.cert.pl/>.

## Reguła działania
1. UpdateCERT.bat ściąga plik tekstowy z listą domen wykorzystując WebClient PowerShella.
2. dns.exe pobiera domeny z pliku i tworzy skrypt output.bat (dodający domeny do DNS) oraz outpudDel.bat (usuwający domeny z DNSu).
3. Uruchamia output.bat i dodaje strefy z rekordami do lokalnego serwera DNS.

Rozwiązanie testowane dla Windows Server 2012 R2 Datacenter. Możliwa automatyzacja z TaskSchedulerem.

Po dodaniu domen serwer DNS stanie się dla nich authority i będzie odpowiadał na zapytania związane z tymi domenami przekierowując ruch na stronę informującą o zagrożeniu. Bezpieczeństwo przed zagrożeniem jest zapewnione na poziomie rozwiązywania nazwy domenowej. Oczywiście istnieją możliwe obejścia w postaci zmiany serwera DNS, jeżeli stosowanie konkretnych nie jest wymuszone.