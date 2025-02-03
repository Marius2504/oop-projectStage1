# GSM Service Management System - Descriere Proiect C++

Acest proiect C++ implementează un sistem de gestionare a unui service GSM, cu următoarele componente principale:

## 🛠️ Clase Principale și Funcționalități

### 1. **`obiectePrimite` (Dispozitive Primite)**
- **Scop**: Gestionează dispozitivele aduse în service pentru reparații.
- **Atribute**:
  - `cod` (unic, generat automat)
  - Stare (`fix`), model, cost reparație, profit, angajat responsabil
  - Detalii piese defecte: cost, cod, nume
- **Funcționalități**:
  - Constructori (cu parametri, copiere), destructor, operatori (`=`, `++`, `+`, `==`, `<<`, `>>`)
  - Metode: `afisareData()` (calculează cost și durată estimată)
  - Getters/Setters pentru toate câmpurile

### 2. **`angajati` (Angajați)**
- **Scop**: Stochează informații despre angajații service-ului.
- **Atribute**:
  - Nume, prenume, ID unic, salariu, istoric salarii, proiecte
- **Funcționalități**:
  - Polimorfism: Metode virtuale `Afisare()` și `Citire()`
  - Operator overloading (`++`, `*`, `-`, `==`)
  - Metoda `afisareS()` (clasifică angajatul ca junior/senior)

### 3. **`produse` (Produse Vândute/Reparate)**
- **Scop**: Gestionează produsele vândute sau reparate (accesorii, dispozitive).
- **Atribute**:
  - Nume, preț, condiție, descriere, piese înlocuite
- **Funcționalități**:
  - Operator overloading (`++`, `+`, `*`, `[]`)
  - Metoda `calc()` (generează reduceri posibile)

### 4. **`client` și `client_fidel` (Clienți)**
- **Scop**: Gestionează informațiile clienților.
- **Atribute**:
  - Nume, adresă, varstă, dispozitiv adus, defect
  - `client_fidel` adaugă discount și valoare totală cheltuită
- **Funcționalități**:
  - Metoda `vars()` (clasifică clientul pe categorii de vârstă)
  - Operator overloading (`+`, `/`, `==`)

### 5. **`tehnician` (Moștenire din `angajati`)**
- **Scop**: Extinde funcționalitatea pentru tehnicieni.
- **Atribute Adiționale**:
  - Vechime, bonus, ierarhie
- **Funcționalități**:
  - Suprascriere metode virtuale de afișare/citire

### 6. **Clase Abstracte și Interfețe**
- **`distribuitor` (Clasă Abstractă)**:
  - Metodă pură `afisare_promotie()`
  - Gestionează nume și dată expirare contract
- **`depozit` (Interfață)**:
  - Metode virtuale `afisare_stoc()` și `afisare_marfa()`
- **`depozitChitiala` (Implementare `depozit`)**:
  - Gestionează cod depozit, locație, marfă

### 7. **`persoana_device` (Relație "Has-A")**
- **Scop**: Asociază un client cu dispozitivul său primit în service.
- **Componente**:
  - Obiect `obiectePrimite`
  - Obiect `client`
  - Dată primire

## 🔑 Caracteristici OOP
- **Moștenire**: `tehnician` ← `angajati`, `client_fidel` ← `client`
- **Polimorfism**: Metode virtuale în `angajati` și `client`
- **Încapsulare**: Toate câmpurile sunt private cu getters/setters
- **Operator Overloading**: `++`, `+`, `==`, `<<`, `>>` în multiple clase
- **Gestionare Memorie**: Destructori cu `delete[]` pentru array-uri
- **Static Members**: Contoare pentru ID-uri unice (`nrObiectePrimite`, `nr` la angajați)

## 🚀 Funcționalități Demo (main())
- Creare obiecte pentru teste: dispozitive, angajați, clienți
- Demonstrație operatori: `++`, `+`, `==`
- Utilizare compoziție (`persoana_device`)
- Testare metode virtuale și abstracte

## ⚙️ Tehnologii Utilizate
- Standard C++11
- Biblioteca `<string>` și `<cstring>` pentru gestionarea șirurilor
- Alocare dinamică și pointeri
- Funcții friend pentru operatori de I/O
